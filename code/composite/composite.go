package main

import "fmt"

type Component interface {
	Process()
}

type Composite struct {
	Name string
	Sons []Component
}

func MakeComposite(Name string) *Composite {
	return &Composite{Name: Name, Sons: []Component{}}
}

func (c *Composite) Process() {
	fmt.Println(c.Name)
	for _, it := range c.Sons {
		it.Process()
	}
}

func (c *Composite) Add(item Component) {
	c.Sons = append(c.Sons, item)
}

type Leaf struct {
	Name string
}

func MakeLeaf(Name string) *Leaf {
	return &Leaf{Name: Name}
}

func (l *Leaf) Process() {
	fmt.Println(l.Name)
}

func Handler(c Component) {
	c.Process()
}

func main() {
	root := MakeComposite("root")
	node1 := MakeComposite("node1")
	node2 := MakeComposite("node2")
	node3 := MakeComposite("node3")
	node4 := MakeComposite("node4")

	leaf1 := MakeLeaf("leaf1")
	leaf2 := MakeLeaf("leaf2")

	root.Add(node1)
	node1.Add(node2)
	node2.Add(leaf1)

	root.Add(node3)
	node3.Add(node4)
	node4.Add(leaf2)

	Handler(root)
}
