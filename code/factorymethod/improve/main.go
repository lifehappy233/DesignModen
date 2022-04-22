package main

import "design.model/factorymethod/improve/splitter"

type MainForm struct {
	FilePath        string
	FileNumber      int
	splitterFactory splitter.SplitterFactory
}

func (m *MainForm) mainWork() {
	split := m.splitterFactory.Create()
	split.Split()
}

func main() {
	mainForm := MainForm{
		splitterFactory: &splitter.VideoSplitterFactory{},
	}
	mainForm.mainWork()
}
