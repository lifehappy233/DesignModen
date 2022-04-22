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

type DatabaseFactory interface {
	CreateConnection() DatabaseConnection
	CreateCommand() DatabaseCommand
	CreateReader() DatabaseReader
}
