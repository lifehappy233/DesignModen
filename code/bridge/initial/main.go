package main

import (
	"fmt"

	"design.model/bridge/initial/messager/mobilemessager"
	"design.model/bridge/initial/messager/pcmessager"
)

func main() {
	pcMessageLite := pcmessager.PcMessagerLite{}
	pcMessagerPerfect := pcmessager.PcMessagerPerfect{}
	mobileMessageLite := mobilemessager.MobileMessagerLite{}
	mobileMessagePerfect := mobilemessager.MobileMessagerPerfect{}
	fmt.Println(pcMessageLite, pcMessagerPerfect, mobileMessageLite, mobileMessagePerfect)
}
