package main

import (
	"design.model/abstractfactory/initial/database"
	"design.model/abstractfactory/initial/database/oracle"
	"design.model/abstractfactory/initial/database/sql"
)

type Handler struct {
	connectionFactory database.ConnectionFactory
	commandFactory    database.CommandFactory
	readerFactory     database.ReaderFactory
}

func (h *Handler) mainWork() {
	connect := h.connectionFactory.CreateConnection()
	connect.Connect()
	command := h.commandFactory.CreateCommand()
	command.BindConnection(connect)
	reader := h.readerFactory.CreateReader()
	reader.Read()
}

func main() {
	handler := Handler{
		connectionFactory: &sql.SqlConnectionFactory{},
		commandFactory:    &oracle.OracleCommandFactory{},
		readerFactory:     &sql.SqlReaderFactory{},
	}
	handler.mainWork()
}
