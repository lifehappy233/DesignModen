package memorystream

type MemoryStream struct {
}

func (f *MemoryStream) Read() string {
	return ""
}

func (f *MemoryStream) Seek() {
}

func (f *MemoryStream) Write() {

}

type CryptoMemoryStream struct {
	MemoryStream
}

func (f *CryptoMemoryStream) Read() string {
	// 加密
	f.MemoryStream.Read()
	// 加密
	return ""
}

func (f *CryptoMemoryStream) Seek() {
	// 加密
	f.MemoryStream.Seek()
	// 加密
}

func (f *CryptoMemoryStream) Write() {
	// 加密
	f.MemoryStream.Write()
	// 加密
}

type BufforedMemoryStream struct {
	MemoryStream
}

func (b *BufforedMemoryStream) Read() string {
	// 缓冲
	b.MemoryStream.Read()
	// 缓冲
	return ""
}

func (b *BufforedMemoryStream) Seek() {
	// 缓冲
	b.MemoryStream.Seek()
	// 缓冲
}

func (b *BufforedMemoryStream) Write() {
	// 缓冲
	b.MemoryStream.Write()
	// 缓冲
}

type CryptoBufforedMemoryStream struct {
	MemoryStream
}

func (cf *CryptoBufforedMemoryStream) Read() string {
	// 加密
	// 缓冲
	cf.MemoryStream.Read()
	// 加密
	// 缓冲
	return ""
}

func (cf *CryptoBufforedMemoryStream) Seek() {
	// 加密
	// 缓冲
	cf.MemoryStream.Seek()
	// 加密
	// 缓冲
}

func (cf *CryptoBufforedMemoryStream) Write() {
	// 加密
	// 缓冲
	cf.MemoryStream.Write()
	// 加密
	// 缓冲
}
