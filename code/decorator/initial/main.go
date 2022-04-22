package main

import (
	"fmt"

	"design.model/decorator/initial/stream/filestream"
)

func main() {
	fileStream := filestream.FileStream{}
	cryptoFileStream := filestream.CryptoBufforedFileStream{}
	bufforedFileStream := filestream.BufforedFileStream{}
	cryptoBufforedFileStream := filestream.CryptoBufforedFileStream{}
	fmt.Println(fileStream, cryptoFileStream, bufforedFileStream, cryptoBufforedFileStream)

	// networkStream......

	// memorystream......
}
