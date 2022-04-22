package splitter

import "fmt"

type FileSplitter struct {
}

func (f *FileSplitter) Split() {
	fmt.Println("FileSplitter")
}

type VideoSplitter struct {
}

func (v *VideoSplitter) Split() {
	fmt.Println("VideoSplitter")
}

type PictureSplitter struct {
}

func (p *PictureSplitter) Split() {
	fmt.Println("PictureSplitter")
}
