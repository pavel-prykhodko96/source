//
//  ViewController.swift
//  4.2 Lab - AppEventCount
//
//  Created by Pavel Prykhodko on 05.05.2020.
//  Copyright © 2020 Pavel Prykhodko. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    // for app delegate:
    @IBOutlet var didFinishLaungingLabel: UILabel!
    @IBOutlet var willTerminateLabel: UILabel!
    // for scene delegate
    @IBOutlet var willResignActiveLabel: UILabel!
    @IBOutlet var didEnterBackgroundLabel: UILabel!
    @IBOutlet var willEnterForegroundLabel: UILabel!
    @IBOutlet var didBecomeActiveLabel: UILabel!
    
    // for app delegate:
    var didFinishLaungingCount: Int = 0
    var willTerminateCount: Int = 0
    // for scene delegate
    var willResignActiveCount: Int = 0
    var didEnterBackgroundCount: Int = 0
    var willEnterForegroundCount: Int = 0
    var didBecomeActiveCount: Int = 0
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        updateView()
    }
    
    func updateView() {
        // for app delegate:
        didFinishLaungingLabel.text = ("The app has launched \(didFinishLaungingCount) time(s)")
        willTerminateLabel.text = ("The app has terminated \(willTerminateCount) time(s)")
        // for scene delegate
        willResignActiveLabel.text = ("The app has resigned active \(willResignActiveCount) time(s)")
        didEnterBackgroundLabel.text = ("The app has entered background \(didEnterBackgroundCount) time(s)")
        willEnterForegroundLabel.text = ("The app has entered foreground \(willEnterForegroundCount) time(s)")
        didBecomeActiveLabel.text = ("The app has become active \(didBecomeActiveCount) time(s)")
        
    }
}

