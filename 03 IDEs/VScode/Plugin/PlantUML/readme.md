# PlantUML

一个通过编码画 UML 的插件

```
+: 可见，public
—: 不可见，private
#: 继承 protected

<|-- 接口实现

```

![alt text](image-1.png)

![alt text](image-2.png)

![alt text](image-3.png)
![alt text](image-4.png)

![alt text](image-5.png)

```plantuml
@startuml
scale 2
class Event {
    +startTime: DateTime
    +venue: string
    +registrationClosed: boolean
    -notifyAttendes()
}
 
class ApplicationUser {
    -userName: string
    -password: string
    +isLocked: boolean
    -suggestRandomPasswod()
    +changeProfilePic()
}
 
class Speaker {
    +openForSpeaking: boolean
    -callForAction()
    +applyAsSpokePerson()
}
 
class Topic {
    +title: string
    +sourceCodeUrl: string
    +downloadMaterials()
}
 
class Attendee {
    -eventAttended: number
    -suggestEventBasedOnPreference()
    +registerForTicket()
}
 
ApplicationUser <|-- Speaker
ApplicationUser <|-- Attendee
Speaker "1" *-- "*" Topic
Event "1" o-- "*" Speaker
Event "1" o-- "*" Attendee
@enduml
```

通过 [在线Server](https://www.plantuml.com/plantuml/uml/SyfFKj2rKt3CoKnELR1Io4ZDoSa70000) 即可生成：

![alt text](image.png)
