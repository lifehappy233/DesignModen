package networkstream

type NetworkStream struct {
}

func (f *NetworkStream) Read() string {
	return ""
}

func (f *NetworkStream) Seek() {
}

func (f *NetworkStream) Write() {

}

type CryptoNetworkStream struct {
	NetworkStream
}

func (f *CryptoNetworkStream) Read() string {
	// 加密
	f.NetworkStream.Read()
	// 加密
	return ""
}

func (f *CryptoNetworkStream) Seek() {
	// 加密
	f.NetworkStream.Seek()
	// 加密
}

func (f *CryptoNetworkStream) Write() {
	// 加密
	f.NetworkStream.Write()
	// 加密
}

type BufforedNetworkStream struct {
	NetworkStream
}

func (b *BufforedNetworkStream) Read() string {
	// 缓冲
	b.NetworkStream.Read()
	// 缓冲
	return ""
}

func (b *BufforedNetworkStream) Seek() {
	// 缓冲
	b.NetworkStream.Seek()
	// 缓冲
}

func (b *BufforedNetworkStream) Write() {
	// 缓冲
	b.NetworkStream.Write()
	// 缓冲
}

type CryptoBufforedNetworkStream struct {
	NetworkStream
}

func (cf *CryptoBufforedNetworkStream) Read() string {
	// 加密
	// 缓冲
	cf.NetworkStream.Read()
	// 加密
	// 缓冲
	return ""
}

func (cf *CryptoBufforedNetworkStream) Seek() {
	// 加密
	// 缓冲
	cf.NetworkStream.Seek()
	// 加密
	// 缓冲
}

func (cf *CryptoBufforedNetworkStream) Write() {
	// 加密
	// 缓冲
	cf.NetworkStream.Write()
	// 加密
	// 缓冲
}
