/*:
 ## Exercise - Type Casting and Inspection
 
 Create a collection of type [Any], including a few doubles, integers, strings, and booleans within the collection. Print the contents of the collection.
 */
func foo () { }
let collection: [Any] = [10, false, 10_009_987_657, 10.17, "JOPA", true, "WEED"]
/*:
 Loop through the collection. For each integer, print "The integer has a value of ", followed by the integer value. Repeat the steps for doubles, strings and booleans.
 */
for item in collection {
    if let int = item as? Int {
        print("Int: \(int)")
    }
    else if let double = item as? Double {
        print("Double: \(double)")
    }
    else if let bool = item as? Bool {
        print("Bool: \(bool)")
    }
    else if let string = item as? String {
        print("String: \(string)")
    }
}
/*:
 Create a [String : Any] dictionary, where the values are a mixture of doubles, integers, strings, and booleans. Print the key/value pairs within the collection
 */
let dict: [String: Any] = ["first": 17,
                           "2": "@_*&%",
                           "boolean": true,
                           "sa": 109.77,
                           "asas": false,
                           "ssadfa": "63.9995",
                           "asawwwws": -100,
                           "why": "because"]
for (key, value) in dict {
    print("\(key): \(value)")
}
/*:
 Create a variable `total` of type `Double` set to 0. Then loop through the dictionary, and add the value of each integer and double to your variable's value. For each string value, add 1 to the total. For each boolean, add 2 to the total if the boolean is `true`, or subtract 3 if it's `false`. Print the value of `total`.
 */
var total: Double = 0
for value in Array(dict.values) {
    if let val = value as? Double {
        total += val
    }
    else if let val = value as? Int {
        total += Double(val)
    }
    else if let _ = value as? String {
        total += 1
    }
    else if let val = value as? Bool {
        if (val == true) {
            total += 2
        } else {
            total -= 3
        }
    }
}
print(total)

/*:
 Create a variable `total2` of type `Double` set to 0. Loop through the collection again, adding up all the integers and doubles. For each string that you come across during the loop, attempt to convert the string into a number, and add that value to the total. Ignore booleans. Print the total.
 */
var total2: Double = 0
for value in Array(dict.values) {
    if let val = value as? Double {
        total2 += val
    }
    else if let val = value as? Int {
        total2 += Double(val)
    }
    else if let valStr = value as? String {
        if let valDouble = Double(valStr) {
            total2 += valDouble
        }
    }
}
print(total2)

//: page 1 of 2  |  [Next: App Exercise - Workout Types](@next)
