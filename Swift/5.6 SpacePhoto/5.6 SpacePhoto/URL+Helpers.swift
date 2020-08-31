//
//  URL+Helpers.swift
//  5.6 SpacePhoto
//
//  Created by Pavel Prykhodko on 28.08.2020.
//  Copyright © 2020 Pavel Prykhodko. All rights reserved.
//

import Foundation

extension URL {
    func withQueries(_ queries: [String: String]) -> URL? {
        var components = URLComponents(url: self, resolvingAgainstBaseURL: true)
        components?.queryItems = queries.map { URLQueryItem(name: $0.0, value: $0.1) }
        return components?.url
    }
    
    func withHTTPS() -> URL? {
        var components = URLComponents(url: self, resolvingAgainstBaseURL: true)
        components?.scheme = "https"
        return components?.url
    }
}
