'use client';
import { Avatar, AvatarFallback } from '@/components/ui/avatar';
import { Bot, User, Loader2 } from 'lucide-react';
import { cn } from '@/lib/utils';
import React from 'react';

export interface ChatMessageProps {
  role: 'user' | 'assistant';
  content: string;
}

const MemoizedReactMarkdown = React.memo(
    ({ children }: { children: string }) => <div>{children}</div>,
    (prevProps, nextProps) => prevProps.children === nextProps.children
);

export function ChatMessage({ role, content }: ChatMessageProps) {
  const isLoading = role === 'assistant' && !content;

  return (
    <div
      className={cn(
        'group flex items-start gap-3 w-full',
        role === 'user' && 'justify-end'
      )}
    >
      {role === 'assistant' && (
        <Avatar className="h-9 w-9 flex-shrink-0">
          <AvatarFallback className="bg-primary text-primary-foreground">
            <Bot className="h-5 w-5" />
          </AvatarFallback>
        </Avatar>
      )}
      <div
        className={cn(
          'max-w-[80%] rounded-lg p-3 text-sm prose prose-sm prose-p:my-0 prose-headings:my-2',
          role === 'user'
            ? 'bg-primary text-primary-foreground'
            : 'bg-card'
        )}
      >
        {isLoading ? (
          <div className="flex items-center gap-2">
            <Loader2 className="h-4 w-4 animate-spin" />
            <span>Thinking...</span>
          </div>
        ) : (
          <MemoizedReactMarkdown>{content}</MemoizedReactMarkdown>
        )}
      </div>
      {role === 'user' && (
        <Avatar className="h-9 w-9 flex-shrink-0">
          <AvatarFallback className="bg-accent text-accent-foreground">
            <User className="h-5 w-5" />
          </AvatarFallback>
        </Avatar>
      )}
    </div>
  );
}
