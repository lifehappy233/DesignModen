package mobilemessager

type MobileMessagerBase struct {
}

func (m *MobileMessagerBase) PlaySound() {
}

func (m *MobileMessagerBase) DrawShape() {
}

func (m *MobileMessagerBase) WriteText() {
}

func (m *MobileMessagerBase) Connect() {
}

type MobileMessagerLite struct {
	MobileMessagerBase
}

func (m *MobileMessagerLite) Login(username, password string) {
	m.MobileMessagerBase.Connect()
}

func (m *MobileMessagerLite) SendMessage(message string) {
	m.MobileMessagerBase.WriteText()
}

func (m *MobileMessagerLite) SendPicture(image string) {
	m.MobileMessagerBase.DrawShape()
}

type MobileMessagerPerfect struct {
	MobileMessagerBase
}

func (m *MobileMessagerPerfect) Login(username, password string) {
	m.MobileMessagerBase.PlaySound()
	m.MobileMessagerBase.Connect()
}

func (m *MobileMessagerPerfect) SendMessage(message string) {
	m.MobileMessagerBase.PlaySound()
	m.MobileMessagerBase.WriteText()
}

func (m *MobileMessagerPerfect) SendPicture(image string) {
	m.MobileMessagerBase.PlaySound()
	m.MobileMessagerBase.DrawShape()
}
