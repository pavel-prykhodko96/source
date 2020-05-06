/*:
 ## Exercise - Adopt Protocols: CustomStringConvertible, Equatable, and Comparable
 
 Create a `Human` class with two properties: `name` of type `String`, and `age` of type `Int`. You'll need to create a memberwise initializer for the class. Initialize two `Human` instances.
 */
class Human : CustomStringConvertible, Equatable, Comparable, Codable {
    var name: String
    var age: Int
    
    var description: String {
        return "Name: \(name), age: \(age)"
    }
    
    init(name: String, age: Int) {
        self.name = name
        self.age = age
    }
    
    static func == (human1: Human, human2: Human) -> Bool {
        return human1.age == human2.age && human1.name == human2.name
    }
    
    static func < (human1: Human, human2: Human) -> Bool {
        return human1.age < human2.age
    }
}

let human1 = Human(name: "Petya", age: 42)
let human2 = Human(name: "Vasya", age: 14)
/*:
 Make the `Human` class adopt the `CustomStringConvertible`. Print both of your previously initialized `Human` objects.
 */
print(human1)
print(human2)

/*:
 Make the `Human` class adopt the `Equatable` protocol. Two instances of `Human` should be considered equal if their names and ages are identical to one another. Print the result of a boolean expression evaluating whether or not your two previously initialized `Human` objects are equal to eachother (using `==`). Then print the result of a boolean expression evaluating whether or not your two previously initialized `Human` objects are not equal to eachother (using `!=`).
 */
print(human1 == human2)
print(human1 != human2)

/*:
 Make the `Human` class adopt the `Comparable` protocol. Sorting should be based on age. Create another three instances of a `Human`, then create an array called `people` of type `[Human]` with all of the `Human` objects that you have initialized. Create a new array called `sortedPeople` of type `[Human]` that is the `people` array sorted by age.
 */
let people: [Human] = [human2, human1, Human(name: "John", age: 23)]
let sortedPeople = people.sorted(by: <)
print(people)
print(sortedPeople)

/*:
 Make the `Human` class adopt the `Codable` protocol. Create a `JSONEncoder` and use it to encode as data one of the `Human` objects you have initialized. Then use that `Data` object to initialize a `String` representing the data that is stored, and print it to the console.
 */
import Foundation
let jsonEncoder = JSONEncoder()
if let jsonData = try? jsonEncoder.encode(human1),
    let jsonString = String(data: jsonData, encoding: .utf8) {
    print(jsonString)
}

//: page 1 of 5  |  [Next: App Exercise - Printable Workouts](@next)
