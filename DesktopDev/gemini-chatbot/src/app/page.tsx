'use client';

import { useState } from 'react';
import { handleFileUpload, handleSendMessage } from '@/app/actions';
import { useToast } from '@/hooks/use-toast';
import { ChatInput } from '@/components/chat-input';
import { ChatMessages } from '@/components/chat-messages';
import type { ChatMessageProps } from '@/components/chat-message';
import { Bot } from 'lucide-react';

export default function Home() {
  const [messages, setMessages] = useState<ChatMessageProps[]>([]);
  const [uploadedFile, setUploadedFile] = useState<File | null>(null);
  const [context, setContext] = useState<string>('');
  const [isLoading, setIsLoading] = useState(false);
  const [isUploading, setIsUploading] = useState(false);
  const { toast } = useToast();

  const handleFileChange = async (file: File) => {
    if (isUploading) return;
    setIsUploading(true);
    setUploadedFile(file);

    const formData = new FormData();
    formData.append('file', file);

    const result = await handleFileUpload(formData);

    if (result.error) {
      toast({
        variant: 'destructive',
        title: 'Upload Failed',
        description: result.error,
      });
      setUploadedFile(null);
    } else {
      setContext(result.extractedText);
      toast({
        title: 'File Processed',
        description:
          'The file has been read and its content is ready to be used as context.',
      });
    }
    setIsUploading(false);
  };

  const handleRemoveFile = () => {
    setUploadedFile(null);
    setContext('');
  };

  const handleSubmit = async (message: string) => {
    if (isLoading) return;
    setIsLoading(true);

    const userMessage: ChatMessageProps = { role: 'user', content: message };
    const assistantPlaceholder: ChatMessageProps = {
      role: 'assistant',
      content: '',
    };

    setMessages((prev) => [...prev, userMessage, assistantPlaceholder]);

    const result = await handleSendMessage(message, context);

    if (result.error) {
      const assistantError: ChatMessageProps = {
        role: 'assistant',
        content: `Error: ${result.error}`,
      };
      setMessages((prev) => {
        const newMessages = [...prev];
        newMessages[newMessages.length - 1] = assistantError;
        return newMessages;
      });
      toast({
        variant: 'destructive',
        title: 'Error',
        description: result.error,
      });
    } else {
      const assistantResponse: ChatMessageProps = {
        role: 'assistant',
        content: result.answer,
      };
      setMessages((prev) => {
        const newMessages = [...prev];
        newMessages[newMessages.length - 1] = assistantResponse;
        return newMessages;
      });
    }

    setIsLoading(false);
  };

  return (
    <div className="flex flex-col h-full">
      <header className="p-4 border-b bg-background shadow-sm flex-shrink-0">
        <h1 className="text-xl font-bold tracking-tight text-foreground">
          Personal AI Assistant
        </h1>
      </header>

      <main className="flex-1 flex flex-col overflow-hidden bg-muted/20">
        {messages.length === 0 ? (
          <div className="flex flex-col items-center justify-center h-full text-center p-4">
            <div className="p-4 bg-primary/10 rounded-full mb-4">
              <Bot className="w-10 h-10 text-primary" />
            </div>
            <h2 className="text-2xl font-semibold mb-2 text-foreground">
              How can I help you today?
            </h2>
            <p className="text-muted-foreground max-w-md">
              Ask me anything, or attach a file (PDF, JPG, PNG) to start a
              conversation about its content.
            </p>
          </div>
        ) : (
          <ChatMessages messages={messages} />
        )}
      </main>

      <ChatInput
        onSubmit={handleSubmit}
        onFileChange={handleFileChange}
        file={uploadedFile}
        onRemoveFile={handleRemoveFile}
        isLoading={isLoading}
        isUploading={isUploading}
      />
    </div>
  );
}
