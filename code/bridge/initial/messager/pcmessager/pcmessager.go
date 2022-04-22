package pcmessager

type PcMessagerBase struct {
}

func (p *PcMessagerBase) PlaySound() {
}

func (p *PcMessagerBase) DrawShape() {
}

func (p *PcMessagerBase) WriteText() {
}

func (p *PcMessagerBase) Connect() {
}

type PcMessagerLite struct {
	PcMessagerBase
}

func (p *PcMessagerLite) Login(username, password string) {
	p.PcMessagerBase.Connect()
}

func (p *PcMessagerLite) SendMessage(message string) {
	p.PcMessagerBase.WriteText()
}

func (p *PcMessagerLite) SendPicture(image string) {
	p.PcMessagerBase.DrawShape()
}

type PcMessagerPerfect struct {
	PcMessagerBase
}

func (p *PcMessagerPerfect) Login(username, password string) {
	p.PcMessagerBase.PlaySound()
	p.PcMessagerBase.Connect()
}

func (p *PcMessagerPerfect) SendMessage(message string) {
	p.PcMessagerBase.PlaySound()
	p.PcMessagerBase.WriteText()
}

func (p *PcMessagerPerfect) SendPicture(image string) {
	p.PcMessagerBase.PlaySound()
	p.PcMessagerBase.DrawShape()
}
