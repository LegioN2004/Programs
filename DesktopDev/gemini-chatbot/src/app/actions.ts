'use server';

import { answerQuestions } from '@/ai/flows/answer-questions';
import { readMedia } from '@/ai/flows/read-media';

export async function handleFileUpload(
  formData: FormData
): Promise<{ extractedText: string } | { error: string }> {
  try {
    const file = formData.get('file') as File;
    if (!file) {
      return { error: 'No file uploaded.' };
    }

    const allowedTypes = ['application/pdf', 'image/jpeg', 'image/png'];
    if (!allowedTypes.includes(file.type)) {
      return {
        error: 'Invalid file type. Only PDF, JPG, and PNG are allowed.',
      };
    }

    const buffer = Buffer.from(await file.arrayBuffer());
    const mediaDataUri = `data:${file.type};base64,${buffer.toString(
      'base64'
    )}`;

    const result = await readMedia({ mediaDataUri });
    return { extractedText: result.extractedText };
  } catch (e) {
    console.error(e);
    return { error: 'Failed to process the file.' };
  }
}

export async function handleSendMessage(
  question: string,
  context: string
): Promise<{ answer: string } | { error: string }> {
  try {
    if (!question.trim()) {
      return { error: 'Question cannot be empty.' };
    }
    const result = await answerQuestions({ question, context });
    return { answer: result.answer };
  } catch (e) {
    console.error(e);
    return { error: 'Failed to get an answer.' };
  }
}
