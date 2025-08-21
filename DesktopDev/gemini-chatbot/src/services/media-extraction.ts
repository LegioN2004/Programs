'use server';

import {ai} from '@/ai/genkit';
import {z} from 'genkit';
import {generate} from 'genkit';

const MediaExtractionInputSchema = z.object({
  mediaDataUri: z.string(),
});
export type MediaExtractionInput = z.infer<typeof MediaExtractionInputSchema>;

const MediaExtractionOutputSchema = z.object({
  extractedText: z.string(),
});
export type MediaExtractionOutput = z.infer<
  typeof MediaExtractionOutputSchema
>;

const mediaExtractionPrompt = ai.definePrompt({
  name: 'mediaExtractionPrompt',
  input: {schema: MediaExtractionInputSchema},
  output: {schema: MediaExtractionOutputSchema},
  prompt: `Extract text from the following media file.

Media: {{media url=mediaDataUri}}`,
});

export async function extractTextFromMedia(
  mediaDataUri: string
): Promise<string> {
  const {output} = await mediaExtractionPrompt({mediaDataUri});
  if (!output) {
    throw new Error('Failed to extract text from media.');
  }
  return output.extractedText;
}
