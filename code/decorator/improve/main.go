package main

import (
	"fmt"

	"design.model/decorator/improve/stream"
)

func main() {
	fileStream := stream.FileStream{}
	cryptoFileStream := stream.CryptoStream{
		StreamFD: &fileStream,
	}
	bufforedFileStream := stream.BufforedStream{
		StreamFD: &fileStream,
	}
	cryptoBufforedFileStream := stream.BufforedStream{
		StreamFD: &cryptoFileStream,
	}
	fmt.Println(fileStream, cryptoFileStream, bufforedFileStream, cryptoBufforedFileStream)
}
