package main

import (
	"fmt"

	"design.model/abstractfactory/improve/database"
	"design.model/abstractfactory/improve/database/oracle"
	"design.model/abstractfactory/improve/database/sql"
)

type Handler struct {
	databaseFactory database.DatabaseFactory
}

func (h *Handler) mainWork() {
	connect := h.databaseFactory.CreateConnection()
	connect.Connect()
	command := h.databaseFactory.CreateCommand()
	command.BindConnection(connect)
	reader := h.databaseFactory.CreateReader()
	reader.Read()
}

func main() {
	handler := Handler{
		databaseFactory: &oracle.OracleFactory{},
	}
	handler.mainWork()

	fmt.Println()

	handler.databaseFactory = &sql.SqlFactory{}
	handler.mainWork()
}
