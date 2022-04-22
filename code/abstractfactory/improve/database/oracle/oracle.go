package oracle

import (
	"fmt"

	"design.model/abstractfactory/improve/database"
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

type OracleFactory struct {
}

func (o *OracleFactory) CreateConnection() database.DatabaseConnection {
	return &OracleConnection{}
}

func (o *OracleFactory) CreateCommand() database.DatabaseCommand {
	return &OracleCommand{}
}
func (o *OracleFactory) CreateReader() database.DatabaseReader {
	return &OracleReader{}
}
