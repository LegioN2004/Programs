'use server';

/**
 * @fileOverview Extracts text from media files (PDF, JPG, PNG) for use as context in the LLM.
 *
 * - readMedia - A function that handles the media reading process.
 * - ReadMediaInput - The input type for the readMedia function.
 * - ReadMediaOutput - The return type for the readMedia function.
 */

import {ai} from '@/ai/genkit';
import {z} from 'genkit';
import {extractTextFromMedia} from '@/services/media-extraction';

const ReadMediaInputSchema = z.object({
  mediaDataUri: z
    .string()
    .describe(
      "A media file (PDF, JPG, PNG) as a data URI that must include a MIME type and use Base64 encoding. Expected format: 'data:<mimetype>;base64,<encoded_data>'."
    ),
});
export type ReadMediaInput = z.infer<typeof ReadMediaInputSchema>;

const ReadMediaOutputSchema = z.object({
  extractedText: z.string().describe('The extracted text content from the media file.'),
});
export type ReadMediaOutput = z.infer<typeof ReadMediaOutputSchema>;

export async function readMedia(input: ReadMediaInput): Promise<ReadMediaOutput> {
  return readMediaFlow(input);
}

const readMediaFlow = ai.defineFlow(
  {
    name: 'readMediaFlow',
    inputSchema: ReadMediaInputSchema,
    outputSchema: ReadMediaOutputSchema,
  },
  async input => {
    const extractedText = await extractTextFromMedia(input.mediaDataUri);
    return {extractedText};
  }
);
