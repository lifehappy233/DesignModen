package sql

import (
	"fmt"

	"design.model/abstractfactory/initial/database"
)

type SqlConnection struct {
}

func (s *SqlConnection) Connect() {
	fmt.Println("Sql Connect ing...")
}

type SqlCommand struct {
}

func (s *SqlCommand) BindConnection(conn database.DatabaseConnection) {
	fmt.Println("Sql BindConnectiong ing...")
}

type SqlReader struct {
}

func (s *SqlReader) Read() {
	fmt.Println("Sql Read ing...")
}

type SqlConnectionFactory struct {
}

func (s *SqlConnectionFactory) CreateConnection() database.DatabaseConnection {
	return &SqlConnection{}
}

type SqlCommandFactory struct {
}

func (s *SqlCommandFactory) CreateCommand() database.DatabaseCommand {
	return &SqlCommand{}
}

type SqlReaderFactory struct {
}

func (s *SqlReaderFactory) CreateReader() database.DatabaseReader {
	return &SqlReader{}
}
