//
//  StoreItem.swift
//  iTunesSearch
//
//  Created by Pavel Prykhodko on 30.08.2020.
//  Copyright © 2020 Caleb Hicks. All rights reserved.
//

import Foundation

struct StoreItem: Codable {
//    var name: String
//    var artist: String
//    var description: String
    var kind: String
//    var artworkURL: URL
    
    enum CodingKeys: String, CodingKey {
//        case name
//        case artist
//        case description
        case kind
//        case artworkURL
    }
    
    enum AdditionalKeys: String, CodingKey {
        case longDescription
    }
    
    init(from decoder: Decoder) throws {
        let valueContainer = try decoder.container(keyedBy: CodingKeys.self)
//        self.name = try valueContainer.decode(String.self, forKey: CodingKeys.name)
//        self.artist = try valueContainer.decode(String.self, forKey: CodingKeys.artist)
        self.kind = try valueContainer.decode(String.self, forKey: CodingKeys.kind)
        print(kind)
//        self.artworkURL = try valueContainer.decode(URL.self, forKey: CodingKeys.artworkURL)
        
//        if let description = try? valueContainer.decode(String.self, forKey: CodingKeys.description) {
//            self.description = description
//        } else {
//            let additionalValues = try decoder.container(keyedBy: AdditionalKeys.self)
//            description = (try? additionalValues.decode(String.self, forKey: AdditionalKeys.longDescription)) ?? ""
//        }
    }
}

struct StoreItems: Codable {
    let results: [StoreItem]
}
