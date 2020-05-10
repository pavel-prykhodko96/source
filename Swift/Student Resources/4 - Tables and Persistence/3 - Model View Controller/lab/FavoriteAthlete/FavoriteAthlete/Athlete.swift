//
//  Athlete.swift
//  FavoriteAthlete
//
//  Created by Pavel Prykhodko on 10.05.2020.
//

import Foundation

struct Athlete {
    var name: String
    var age: String
    var league: String
    var team: String
    
    var description: String {
        return "\(name) is \(age) years old and plays for the \(team) in the \(league)"
    }
}
