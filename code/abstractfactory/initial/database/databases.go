package database

type DatabaseConnection interface {
	Connect()
}

type DatabaseCommand interface {
	BindConnection(conn DatabaseConnection)
}

type DatabaseReader interface {
	Read()
}

type ConnectionFactory interface {
	CreateConnection() DatabaseConnection
}

type CommandFactory interface {
	CreateCommand() DatabaseCommand
}

type ReaderFactory interface {
	CreateReader() DatabaseReader
}
