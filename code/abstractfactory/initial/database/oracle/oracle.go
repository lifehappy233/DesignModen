package oracle

import (
	"fmt"

	"design.model/abstractfactory/initial/database"
)

type OracleConnection struct {
}

func (o *OracleConnection) Connect() {
	fmt.Println("Oracle Connect ing...")
}

type OracleCommand struct {
}

func (o *OracleCommand) BindConnection(conn database.DatabaseConnection) {
	fmt.Println("Oracle BindConnectiong ing...")
}

type OracleReader struct {
}

func (o *OracleReader) Read() {
	fmt.Println("Oracle Read ing...")
}

type OracleConnectionFactory struct {
}

func (o *OracleConnectionFactory) CreateConnection() database.DatabaseConnection {
	return &OracleConnection{}
}

type OracleCommandFactory struct {
}

func (o *OracleCommandFactory) CreateCommand() database.DatabaseCommand {
	return &OracleCommand{}
}

type OracleReaderFactory struct {
}

func (o *OracleCommandFactory) CreateReader() database.DatabaseReader {
	return &OracleReader{}
}
