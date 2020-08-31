//
//  StoreItemController.swift
//  iTunesSearch
//
//  Created by Pavel Prykhodko on 30.08.2020.
//  Copyright © 2020 Caleb Hicks. All rights reserved.
//

import Foundation

class StoreItemController {
    func fetchItems(matching query: [String: String], completion: @escaping ([StoreItem]?) -> Void) {
        let baseURL = URL(string: "https://itunes.apple.com/search?")!
        
        let fullURL = baseURL.withQueries(query)!
        
        let task = URLSession.shared.dataTask(with: fullURL) { (data, response, error) in
            let jsonDecoder = JSONDecoder()
            if let data = data,
                let storeItems = try? jsonDecoder.decode(StoreItems.self, from: data) {
                completion(storeItems.results)
            } else {
                print("Either no data was returned, or data was not properly decoded.")
                completion(nil)
                return
            }
        }
        task.resume()
    }
}
