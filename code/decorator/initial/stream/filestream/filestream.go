package filestream

type FileStream struct {
}

func (f *FileStream) Read() string {
	return ""
}

func (f *FileStream) Seek() {
}

func (f *FileStream) Write() {

}

type CryptoFileStream struct {
	FileStream
}

func (f *CryptoFileStream) Read() string {
	// 加密
	f.FileStream.Read()
	// 加密
	return ""
}

func (f *CryptoFileStream) Seek() {
	// 加密
	f.FileStream.Seek()
	// 加密
}

func (f *CryptoFileStream) Write() {
	// 加密
	f.FileStream.Write()
	// 加密
}

type BufforedFileStream struct {
	FileStream
}

func (b *BufforedFileStream) Read() string {
	// 缓冲
	b.FileStream.Read()
	// 缓冲
	return ""
}

func (b *BufforedFileStream) Seek() {
	// 缓冲
	b.FileStream.Seek()
	// 缓冲
}

func (b *BufforedFileStream) Write() {
	// 缓冲
	b.FileStream.Write()
	// 缓冲
}

type CryptoBufforedFileStream struct {
	FileStream
}

func (cf *CryptoBufforedFileStream) Read() string {
	// 加密
	// 缓冲
	cf.FileStream.Read()
	// 加密
	// 缓冲
	return ""
}

func (cf *CryptoBufforedFileStream) Seek() {
	// 加密
	// 缓冲
	cf.FileStream.Seek()
	// 加密
	// 缓冲
}

func (cf *CryptoBufforedFileStream) Write() {
	// 加密
	// 缓冲
	cf.FileStream.Write()
	// 加密
	// 缓冲
}
