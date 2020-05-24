import UIKit

struct Note: Codable {
    let title: String
    let text: String
    let timestamp: Date
}

let newNote = Note(title: "Grocery run", text: "Pick up mayonnaise, mustard...", timestamp: Date())
let note1 = Note(title: "1", text: "Pick up mayonnaise, mustard...", timestamp: Date())
let note2 = Note(title: "2", text: "Pick up mayonnaise, mustard...", timestamp: Date())
let note3 = Note(title: "3", text: "Pick up mayonnaise, mustard...", timestamp: Date())
let notes = [note1, note2, note3]

let documentsDirectory = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first!
let archiveURL = documentsDirectory.appendingPathComponent("notes_test").appendingPathExtension("plist")

let propertyListEncoder = PropertyListEncoder()
let encodedNote: Data? = try? propertyListEncoder.encode(notes)
try? encodedNote?.write(to: archiveURL, options: .noFileProtection)

let propertyListDecoder = PropertyListDecoder()
if let retrievedNoteData = try? Data(contentsOf: archiveURL),
    let decodedNote = try? propertyListDecoder.decode(Array<Note>.self, from: retrievedNoteData) {
    print(decodedNote)
}
