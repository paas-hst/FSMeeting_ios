//
//  FSViewController.m
//  FSMeeting_ios
//
//  Created by zhongxy on 12/20/2023.
//  Copyright (c) 2023 zhongxy. All rights reserved.
//

#import "FSViewController.h"
#import <FSMeeting/FSMeeting.h>
@interface FSViewController ()

@end

@implementation FSViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [[FSMeeting shared] setClientInfo:@"" secret:@"" serverip:@"" serverport:@"" viewCtrl:self isShowHud:YES result:^(BOOL isSuccess) {
            
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
