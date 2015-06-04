//
//  IndoorsLocationListener.m
//  Indoors
//
//  Created by Gerhard Zeissl on 02.12.12.
//  Copyright (c) 2012 Indoors. All rights reserved.
//


#import "IDSBuilding.h"
#import "IDSCoordinate.h"
#import "IndoorsDelegate.h"
#import "IDSContext.h"

/**
 * Main interface for localization updates from the indoo.rs service.
 */
@protocol IndoorsLocationListener <NSObject>

/**
 @brief New user position.
 */
- (void)positionUpdated:(IDSCoordinate *)userPosition;

/**
 The user position could not be determined. You may use this to display a warning like "low signal, computing...".
 */
- (void)weakSignal;
    
/**
 Current orientation in degrees.
 
 For convenience the angle is relative to the building map, not relative to North.
 More precisely the returned value is the clockwise oriented angle on the x,y
 plane starting at the y-axis.

 @param orientation Current orientation in degrees.
 */
- (void)orientationUpdated:(float)orientation;
    
/**
 The floor has changed. This will be called before you receive position updates for the new floor.
 
 @param floorLevel Level of the floor (..., -1=Sub1, 0=Ground, 1=Floor1,...).
 @param name Name of the floor.
 */
- (void)changedFloor:(int)floorLevel withName:(NSString*)name;

/**
 The user entered or left a zone.

 @param zones All zones containing the current user position.
 */
- (void)zonesEntered:(NSArray *)zones;

/**
 Reports the current context of the user.
 
 @param context Context information from the location service.
 */
- (void)contextUpdated:(IDSContext *)context;

@end
