//
//  ViewController.swift
//  5.6 SpacePhoto
//
//  Created by Pavel Prykhodko on 24.08.2020.
//  Copyright © 2020 Pavel Prykhodko. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet var photoImage: UIImageView!
    @IBOutlet var descriptionLabel: UILabel!
    @IBOutlet var copyrightLabel: UILabel!
    
    let photoInfoController = PhotoInfoController()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        descriptionLabel.text = ""
        copyrightLabel.text = ""
        
        UIApplication.shared.isNetworkActivityIndicatorVisible = true
        photoInfoController.fetchPhotoInfo { (photoInfo) in
            if let photoInfo = photoInfo {
                self.updateUI(with: photoInfo)
            }
        }
    }
    
    func updateUI(with photoInfo: PhotoInfo) {
        guard let url = photoInfo.url.withHTTPS() else { return }
        
        let task = URLSession.shared.dataTask(with: url) { (data, response, error) in
        
            guard let data = data,
                let image = UIImage(data: data) else { return }
            DispatchQueue.main.async {
                self.title = photoInfo.title
                self.photoImage.image = image
                self.descriptionLabel.text = photoInfo.description
                if let copyright = photoInfo.copyright {
                    self.copyrightLabel.text = "Copyright \(copyright)"
                } else {
                    self.copyrightLabel.isHidden = true
                }
                UIApplication.shared.isNetworkActivityIndicatorVisible = false
            }
        }
        task.resume()
    }
}

