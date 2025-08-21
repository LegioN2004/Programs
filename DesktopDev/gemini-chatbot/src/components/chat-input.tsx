'use client';

import React, { useRef, useState } from 'react';
import { Textarea } from '@/components/ui/textarea';
import { Button } from '@/components/ui/button';
import { Paperclip, Send, X, Loader2 } from 'lucide-react';
import { Badge } from '@/components/ui/badge';
import { Tooltip, TooltipContent, TooltipProvider, TooltipTrigger } from './ui/tooltip';

interface ChatInputProps {
  onSubmit: (message: string) => void;
  onFileChange: (file: File) => void;
  file: File | null;
  onRemoveFile: () => void;
  isLoading: boolean;
  isUploading: boolean;
}

export function ChatInput({
  onSubmit,
  onFileChange,
  file,
  onRemoveFile,
  isLoading,
  isUploading,
}: ChatInputProps) {
  const [message, setMessage] = useState('');
  const fileInputRef = useRef<HTMLInputElement>(null);

  const handleTextareaKeyDown = (
    e: React.KeyboardEvent<HTMLTextAreaElement>
  ) => {
    if (e.key === 'Enter' && !e.shiftKey) {
      e.preventDefault();
      handleSubmit();
    }
  };

  const handleSubmit = () => {
    if (message.trim() && !isLoading) {
      onSubmit(message);
      setMessage('');
    }
  };

  const handleFileSelect = (e: React.ChangeEvent<HTMLInputElement>) => {
    const selectedFile = e.target.files?.[0];
    if (selectedFile) {
      onFileChange(selectedFile);
    }
    // Reset file input to allow selecting the same file again
    if (e.target) {
      e.target.value = '';
    }
  };

  const handleAttachClick = () => {
    fileInputRef.current?.click();
  };

  const isDisabled = isLoading || isUploading;

  return (
    <TooltipProvider>
    <div className="p-4 bg-background border-t">
      <div className="relative">
        {file && (
          <div className="absolute bottom-full left-0 mb-2">
            <Badge variant="secondary" className="flex items-center gap-2">
              <Paperclip className='h-3 w-3' />
              <span>{file.name}</span>
              <button
                onClick={onRemoveFile}
                disabled={isDisabled}
                className="rounded-full hover:bg-muted-foreground/20 p-0.5 disabled:opacity-50"
                aria-label="Remove file"
              >
                <X className="h-3 w-3" />
              </button>
            </Badge>
          </div>
        )}
        <Textarea
          placeholder={
            file
              ? 'Ask a question about the attached file...'
              : 'Type your message or attach a file...'
          }
          rows={1}
          value={message}
          onChange={(e) => setMessage(e.target.value)}
          onKeyDown={handleTextareaKeyDown}
          disabled={isDisabled}
          className="pr-24 min-h-[48px] resize-none"
        />
        <div className="absolute right-2 top-1/2 -translate-y-1/2 flex items-center gap-1">
          <Tooltip>
            <TooltipTrigger asChild>
              <Button
                size="icon"
                variant="ghost"
                onClick={handleAttachClick}
                disabled={isDisabled}
                aria-label="Attach file"
              >
                {isUploading ? (
                  <Loader2 className="animate-spin" />
                ) : (
                  <Paperclip />
                )}
              </Button>
            </TooltipTrigger>
            <TooltipContent>
              <p>Attach a file (PDF, JPG, PNG)</p>
            </TooltipContent>
          </Tooltip>
          
          <input
            type="file"
            ref={fileInputRef}
            onChange={handleFileSelect}
            className="hidden"
            accept=".pdf,.jpg,.jpeg,.png"
            disabled={isDisabled}
          />
          <Button
            size="icon"
            onClick={handleSubmit}
            disabled={isDisabled || !message.trim()}
            aria-label="Send message"
          >
            <Send />
          </Button>
        </div>
      </div>
    </div>
    </TooltipProvider>
  );
}
