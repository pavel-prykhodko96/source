import UIKit
import PlaygroundSupport
PlaygroundPage.current.needsIndefiniteExecution = true

extension URL {
    func withQueries(_ queries: [String: String]) -> URL? {
        var components = URLComponents(url: self, resolvingAgainstBaseURL: true)
        components?.queryItems = queries.map { URLQueryItem(name: $0.0, value: $0.1) }
        return components?.url
    }
}

struct StoreItem: Codable {
    var artistName: String
    var kind: String
    var trackName: String
    var trackViewUrl: URL
    
    enum CodingKeys: String, CodingKey {
        case artistName
        case kind
        case trackName
        case trackViewUrl
    }
    
    init(from decoder: Decoder) throws {
        let valueContainer = try decoder.container(keyedBy: CodingKeys.self)
        self.artistName = try valueContainer.decode(String.self, forKey: CodingKeys.artistName)
        self.kind = try valueContainer.decode(String.self, forKey: CodingKeys.kind)
        self.trackName = try valueContainer.decode(String.self, forKey: CodingKeys.trackName)
        self.trackViewUrl = try valueContainer.decode(URL.self, forKey: CodingKeys.trackViewUrl)
    }
}

struct StoreItems: Codable {
    let results: [StoreItem]
}

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
        PlaygroundPage.current.finishExecution()
    }
    
    task.resume()
}

let searchQuery: [String: String] = [
    "term": "Ivan Dorn",
    "media": "music"
]

fetchItems(matching: searchQuery) { (storeItems) in
    if let storeItems = storeItems {
        for item in storeItems {
            print(item.trackName)
        }
    }
}
