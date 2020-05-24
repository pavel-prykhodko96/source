//
//  Emoji.swift
//  4.5 EmojiDictionary
//
//  Created by Pavel Prykhodko on 13.05.2020.
//  Copyright © 2020 Pavel Prykhodko. All rights reserved.
//

import Foundation

struct Emoji : Codable {
    var symbol: String
    var name: String
    var description: String
    var usage: String
    
    static var ArchiveUrl: URL {
        let documentsDirectory = FileManager.default.urls(for: .documentDirectory, in: .userDomainMask).first!
        return documentsDirectory.appendingPathComponent("emojis").appendingPathExtension("plist")
    }
    
    init(symbol: String, name: String, description: String, usage: String) {
        self.symbol = symbol
        self.name = name
        self.description = description
        self.usage = usage
    }
    
    static func saveToFile(emojis: [Emoji]) {
        let propertyListEncoder = PropertyListEncoder()
        let encodedEmojis = try? propertyListEncoder.encode(emojis)
        try? encodedEmojis?.write(to: ArchiveUrl, options: .noFileProtection)
    }
    static func loadFromFile() -> [Emoji]? {
        let propertyListDecoder = PropertyListDecoder()
        
        guard let retrievedEmojisData = try? Data(contentsOf: ArchiveUrl) else {return nil}
        
        guard let decodedEmojis = try? propertyListDecoder.decode(Array<Emoji>.self, from: retrievedEmojisData) else {return nil}
        
        return decodedEmojis
    }
    static func loadSampleEmojis() -> [Emoji] {
        return [
            Emoji(symbol: "😂", name: "Laughing face", description: "Maximal degree of laughing", usage: "show that something is extremely funny"),
            Emoji(symbol: "💔", name: "Broken heart", description: "The heart that was broken", usage: "upset, sarcasm"),
            Emoji(symbol: "💩", name: "Poop", description: "Piece of shit", usage: "relation, joke"),
            Emoji(symbol: "⛈", name: "Lightning with rain", description: "Lightning with rain weather", usage: "describe weather"),
        ]
    }
}
