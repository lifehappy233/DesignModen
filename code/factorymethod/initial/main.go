package main

import "design.model/factorymethod/initial/splitter"

type MainForm struct {
	FilePath   string
	FileNumber int
}

func (m *MainForm) MainWork(op string) {
	if op == "FileSplitter" {
		Splitter := splitter.FileSplitter{}
		Splitter.Split()
	} else if op == "VideoSplitter" {
		Splitter := splitter.VideoSplitter{}
		Splitter.Split()
	} else if op == "PictureSplitter" {
		Splitter := splitter.PictureSplitter{}
		Splitter.Split()
	}
}

func main() {
	mainform := MainForm{}
	mainform.MainWork("PictureSplitter")
}
