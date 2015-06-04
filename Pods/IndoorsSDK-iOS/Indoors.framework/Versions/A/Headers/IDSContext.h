//
//  IDSContext.h
//  Indoors
//
//  Created by Philipp König on 23.07.14.
//  Copyright (c) 2014 Indoors. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, Context) {
    IDS_CONTEXT_STATIONARY,
    IDS_CONTEXT_MOVING,
    IDS_CONTEXT_WALKING
};

typedef NS_ENUM(NSUInteger, State) {
    IDS_STATE_BEGAN,
    IDS_STATE_CHANGED,
    IDS_STATE_ENDED
};

@interface IDSContext : NSObject

@property (nonatomic) Context context;
@property (nonatomic) State state;

@end
