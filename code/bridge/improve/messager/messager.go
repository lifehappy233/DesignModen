package messager

type Messager interface {
	Login(username, password string)
	SendMessage(message string)
	SendPicture(image string)
}

type MessagerImp interface {
	PlaySound()
	DrawShape()
	WriteText()
	Connect()
}

type MessagerLite struct {
	Messagerimp MessagerImp
}

func (m *MessagerLite) Login(username, password string) {
	m.Messagerimp.Connect()
}

func (m *MessagerLite) SendMessage(message string) {
	m.Messagerimp.WriteText()
}

func (m *MessagerLite) SendPicture(image string) {
	m.Messagerimp.DrawShape()
}

type MessagerPerfect struct {
	Messagerimp MessagerImp
}

func (m *MessagerPerfect) Login(username, password string) {
	m.Messagerimp.Connect()
}

func (m *MessagerPerfect) SendMessage(message string) {
	m.Messagerimp.WriteText()
}

func (m *MessagerPerfect) SendPicture(image string) {
	m.Messagerimp.DrawShape()
}
