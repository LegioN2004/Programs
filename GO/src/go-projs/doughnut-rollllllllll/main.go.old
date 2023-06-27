package main

import (
	"fmt"
	"math"
	"time"
)

const (
	Width       = 80
	Height      = 24
	Scale       = 0.04
	AnimationDelay = time.Millisecond * 50
)

func main() {
	for {
		for i := 0; i < Height; i++ {
			for j := 0; j < Width; j++ {
				x := float64(j) * 0.5
				y := float64(i) * 0.2

				z1 := math.Sin(x*Scale) + math.Cos(y*Scale)
				z2 := math.Sin((x+1)*Scale) + math.Cos(y*Scale)
				z3 := math.Sin(x*Scale) + math.Cos((y+1)*Scale)
				z4 := math.Sin((x+1)*Scale) + math.Cos((y+1)*Scale)

				average := (z1 + z2 + z3 + z4) / 4
				gray := int(average*10 + 10)

				fmt.Print(GrayScaleToChar(gray))
			}
			fmt.Println()
		}
		time.Sleep(AnimationDelay)
		fmt.Print("\033[H\033[2J") // Clear the terminal screen
	}
}

func GrayScaleToChar(gray int) string {
	chars := "@%#*+=-:. "
	if gray < 0 {
		gray = 0
	}
	if gray >= len(chars) {
		gray = len(chars) - 1
	}
	return string(chars[gray])
}
