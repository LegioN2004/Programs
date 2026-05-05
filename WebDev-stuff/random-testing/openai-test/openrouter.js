import "dotenv/config";
import OpenAI from "openai";

const client = new OpenAI({
    apiKey: process.env.OPENROUTER_API_KEY,
    baseURL: "https://openrouter.ai/api/v1",
});

async function main() {
    try {
        const response = await client.chat.completions.create({
            model: "openrouter/free", // Free tier available
            messages: [
                {
                    role: "system",
                    content: "You are a helpful coding assistant.",
                },
                {
                    role: "user",
                    content:
                        "Explain async/await in JavaScript with a pirate example.",
                },
            ],
        });

        console.log(response.choices[0].message.content);
    } catch (error) {
        console.error("Error:", error.message);
    }
}

main();
