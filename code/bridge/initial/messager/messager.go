package messager

type Messager interface {
	Login(username, password string)
	SendMessage(message string)
	SendPicture(image string)

	PlaySound()
	DrawShape()
	WriteText()
	Connect()
}
