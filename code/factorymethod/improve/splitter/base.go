package splitter

type Splitter interface {
	Split()
}

type SplitterFactory interface {
	Create() Splitter
}
