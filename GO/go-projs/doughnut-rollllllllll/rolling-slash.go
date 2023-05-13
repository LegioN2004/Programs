package main

import (
    "fmt"
    "time"
)

func main() {
    for i := 0; i < 50; i++ {
        fmt.Print("\r[|]")
        time.Sleep(100 * time.Millisecond)
        fmt.Print("\r[/]")
        time.Sleep(100 * time.Millisecond)
        fmt.Print("\r[-]")
        time.Sleep(100 * time.Millisecond)
        fmt.Print("\r[\\]")
        time.Sleep(100 * time.Millisecond)
    }
    fmt.Println("\nRolling doughnut animation complete!")
}
