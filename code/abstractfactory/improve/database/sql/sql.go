package sql

import (
	"fmt"

	"design.model/abstractfactory/improve/database"
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

type SqlFactory struct {
}

func (s *SqlFactory) CreateConnection() database.DatabaseConnection {
	return &SqlConnection{}
}

func (s *SqlFactory) CreateCommand() database.DatabaseCommand {
	return &SqlCommand{}
}
func (s *SqlFactory) CreateReader() database.DatabaseReader {
	return &SqlReader{}
}
