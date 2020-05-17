//
//  Emoji.swift
//  4.5 EmojiDictionary
//
//  Created by Pavel Prykhodko on 13.05.2020.
//  Copyright © 2020 Pavel Prykhodko. All rights reserved.
//

import Foundation

struct Emoji {
    var symbol: Character
    var name: String
    var description: String
    var usage: String
    
    init(symbol: Character, name: String, description: String, usage: String) {
        self.symbol = symbol
        self.name = name
        self.description = description
        self.usage = usage
    }
}
