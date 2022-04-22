package main

import (
	"fmt"

	"design.model/bridge/improve/messager"
	"design.model/bridge/improve/messager/mobilemessager"
	"design.model/bridge/improve/messager/pcmessager"
)

func main() {
	/*
		pcMessageLite := pcmessager.PcMessagerLite{}
		pcMessagerPerfect := pcmessager.PcMessagerPerfect{}
		mobileMessageLite := mobilemessager.MobileMessagerLite{}
		mobileMessagePerfect := mobilemessager.MobileMessagerPerfect{}
		fmt.Println(pcMessageLite, pcMessagerPerfect, mobileMessageLite, mobileMessagePerfect)
	*/
	pcMessagerLite := messager.MessagerLite{
		Messagerimp: &pcmessager.PcMessagerImp{},
	}

	pcMessagerPerfect := messager.MessagerPerfect{
		Messagerimp: &pcmessager.PcMessagerImp{},
	}

	mobileMessagerLite := messager.MessagerLite{
		Messagerimp: &mobilemessager.MobileMessagerImp{},
	}

	mobileMessagePerfect := messager.MessagerPerfect{
		Messagerimp: &mobilemessager.MobileMessagerImp{},
	}

	fmt.Println(pcMessagerLite, pcMessagerPerfect, mobileMessagerLite, mobileMessagePerfect)
}
