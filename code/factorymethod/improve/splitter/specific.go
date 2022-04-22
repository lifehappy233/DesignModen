package splitter

import "fmt"

type FileSplitter struct {
}

func (f *FileSplitter) Split() {
	fmt.Println("FileSplitter")
}

type FileSplitterFactory struct {
}

func (f *FileSplitterFactory) Create() Splitter {
	return &FileSplitter{}
}

type VideoSplitter struct {
}

func (v *VideoSplitter) Split() {
	fmt.Println("VideoSplitter")
}

type VideoSplitterFactory struct {
}

func (v *VideoSplitterFactory) Create() Splitter {
	return &VideoSplitter{}
}

type PictureSplitter struct {
}

func (p *PictureSplitter) Split() {
	fmt.Println("PictureSplitter")
}

type PictureSplitterFactory struct {
}

func (p *PictureSplitterFactory) Create() Splitter {
	return &PictureSplitter{}
}
