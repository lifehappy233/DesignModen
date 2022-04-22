package stream

type Stream interface {
	Write()
	Read() string
	Seek()
}

type FileStream struct {
}

func (f *FileStream) Write() {
}

func (f *FileStream) Read() string {
	return ""
}

func (f *FileStream) Seek() {
}

type NetworkStream struct {
}

func (n *NetworkStream) Write() {
}

func (n *NetworkStream) Read() string {
	return ""
}

func (n *NetworkStream) Seek() {
}

type MemoryStream struct {
}

func (m *MemoryStream) Write() {
}

func (m *MemoryStream) Read() string {
	return ""
}

func (m *MemoryStream) Seek() {
}

type CryptoStream struct {
	StreamFD Stream
}

func (c *CryptoStream) Write() {
	// 加密
	c.StreamFD.Write()
	// 加密
}

func (c *CryptoStream) Read() string {
	// 加密
	c.StreamFD.Read()
	// 加密
	return ""
}

func (c *CryptoStream) Seek() {
	// 加密
	c.StreamFD.Seek()
	// 加密
}

type BufforedStream struct {
	StreamFD Stream
}

func (b *BufforedStream) Write() {
	// 缓冲
	b.StreamFD.Write()
	// 缓冲
}

func (b *BufforedStream) Read() string {
	// 缓冲
	b.StreamFD.Read()
	// 缓冲
	return ""
}

func (b *BufforedStream) Seek() {
	// 缓冲
	b.StreamFD.Seek()
	// 缓冲
}
