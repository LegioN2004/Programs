package main

import (
    "fmt"
    "time"
)

func main() {
    // Create a slice of characters to represent the doughnut.
    doughnut := []string{
        "   /\\",
        "  /  \\",
        " /    \\",
        "/      \\",
        " \\     /",
        "  \\   /",
        "   \\ /",
        "    \\/",
    }

    // Set the initial rotation angle.
    rotationAngle := 0

    // Start a loop that will run indefinitely.
    for {
        // Clear the terminal screen.
        fmt.Println("\x1b[2J")

        // Rotate the doughnut by the current rotation angle.
        for i, char := range doughnut {
            doughnut[i] = doughnut[i][rotationAngle%len(char)]
        }

        // Print the doughnut to the terminal screen.
        for _, char := range doughnut {
            fmt.Print(char)
        }

        // Sleep for a short amount of time.
        time.Sleep(100 * time.Millisecond)

        // Increase the rotation angle by 1 degree.
        rotationAngle++
    }
}

