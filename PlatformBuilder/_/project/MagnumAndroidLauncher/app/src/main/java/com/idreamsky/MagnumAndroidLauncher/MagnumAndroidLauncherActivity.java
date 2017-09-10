/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.idreamsky.MagnumAndroidLauncher;

import android.app.Activity;
import android.os.Bundle;
import java.io.File;
import android.content.Context;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.List;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.util.Log;
import android.view.Display;
import android.view.MotionEvent;
import android.view.Surface;
import android.view.View;
import android.view.View.OnTouchListener;

public class MagnumAndroidLauncherActivity extends Activity
{
    JNIView mView;

    // public static final int TYPE_ACCELEROMETER = 1;
    // public static final int TYPE_MAGNETIC_FIELD = 2;
    // public static final int TYPE_ORIENTATION = 3;
    // public static final int TYPE_GYROSCOPE = 4;
    // public static final int TYPE_LIGHT = 5;
    // public static final int TYPE_PRESSURE = 6;
    // public static final int TYPE_TEMPERATURE = 7;
    // public static final int TYPE_PROXIMITY = 8;
    // public static final int TYPE_GRAVITY = 9;
    // public static final int TYPE_LINEAR_ACCELERATION = 10;
    // public static final int TYPE_ROTATION_VECTOR = 11;
    // public static final int TYPE_RELATIVE_HUMIDITY = 12;
    // public static final int TYPE_AMBIENT_TEMPERATURE = 13;
    // public static final int TYPE_MAGNETIC_FIELD_UNCALIBRATED = 14;
    // public static final int TYPE_GAME_ROTATION_VECTOR = 15;
    // public static final int TYPE_GYROSCOPE_UNCALIBRATED = 16;
    // public static final int TYPE_SIGNIFICANT_MOTION = 17;
    // public static final int TYPE_STEP_DETECTOR = 18;
    // public static final int TYPE_STEP_COUNTER = 19;

    SensorManager sensorManager = null;

    // ----------------------------------------------------------------------------------
    boolean accelerationSensorPresent = false;
    Sensor accelerationSensor;
    SensorEventListener accelerationSensorListener = null;
    float gravity_x, gravity_y, gravity_z;
    int width, height;

    public void initTouchSensor()
    {
        int currentapiVersion = android.os.Build.VERSION.SDK_INT;

        Display display = this.getWindowManager().getDefaultDisplay();
        width = display.getWidth();
        height = display.getHeight();

        mView.setOnTouchListener(new OnTouchListener()
        {
            public boolean onTouch(View v, MotionEvent ev)
            {
                int action = ev.getAction();
                int actionCode = action & MotionEvent.ACTION_MASK;

                if (actionCode == 0 || actionCode == 5) // down or pointer down (BEGIN)
                {
                    int pID = action >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;

                    int x = (int)ev.getX();
                    int y = (int)ev.getY();
                    JNI.onMouseDown(0,
                                    pID,
                                    ev.getX()            * 2.0f / width - 1.0f,
                                    (height - ev.getY()) * 2.0f / height - 1.0f);
                }
                else if (actionCode == 2) // moving (MOVE)
                {
                    int pID = action >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;

                    int x = (int)ev.getX();
                    int y = (int)ev.getY();
                    JNI.onMouseMoved(0,
                                     pID,
                                     ev.getX()            * 2.0f / width - 1.0f,
                                     (height - ev.getY()) * 2.0f / height - 1.0f);
                }
                else if (actionCode == 1 || actionCode == 6) // up or pointer (ENDED)
                {
                    int pID = action >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;

                    int x = (int)ev.getX();
                    int y = (int)ev.getY();
                    JNI.onMouseUp(0,
                                  pID,
                                  ev.getX()            * 2.0f / width - 1.0f,
                                  (height - ev.getY()) * 2.0f / height - 1.0f);
                }
                else if (actionCode == 3) // cancelled because of this app was put to background (CANCELLED)
                {
                    int pID = action >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;

                    int x = (int)ev.getX();
                    int y = (int)ev.getY();
                    JNI.onMouseUp(0,
                                  pID,
                                  ev.getX()            * 2.0f / width - 1.0f,
                                  (height - ev.getY()) * 2.0f / height - 1.0f);
                }

                return true;
            }
        });
    }

    public void initAccelerationSensor()
    {
        List<Sensor> sensorList = sensorManager.getSensorList(Sensor.TYPE_ACCELEROMETER);

        gravity_x = 0.0f;
        gravity_y = 0.0f;
        gravity_z = 0.0f;

        if (sensorList.size() > 0)
        {
            accelerationSensorPresent = true;
            accelerationSensor = sensorList.get(0);
        }
        else
        {
            accelerationSensorPresent = false;
        }

        accelerationSensorListener = new SensorEventListener()
        {
            public void onAccuracyChanged(Sensor sensor, int accuracy)
            {
                // Log.d("EpicForce",
                // "accelerationSensorListener onAccuracyChanged: " + sensor +
                // ", accuracy: " + accuracy);
            }

            public void onSensorChanged(SensorEvent event)
            {
                synchronized (this)
                {
                    // /////////////////////////////////////////////////////////////
                    // acceleration
                    float acceleration_x = event.values[0];
                    float acceleration_y = event.values[1];
                    float acceleration_z = event.values[2];

                    // final float alpha = 0.8f;
                    // gravity_x = alpha * gravity_x + (1 - alpha) *
                    // acceleration_x;
                    // gravity_y = alpha * gravity_y + (1 - alpha) *
                    // acceleration_y;
                    // gravity_z = alpha * gravity_z + (1 - alpha) *
                    // acceleration_z;

                    // float linear_acceleration_x = acceleration_x;// -
                    // gravity_x;
                    // float linear_acceleration_y = acceleration_y;// -
                    // gravity_y;
                    // float linear_acceleration_z = acceleration_z;// -
                    // gravity_z;

                    // EpicforceJNI.gameAppSetAcc(acceleration_x,
                    // acceleration_y, acceleration_z);
                    //mView.inputdata.setAcc(acceleration_x, acceleration_y,
                    //acceleration_z);
                    Display display = (MagnumAndroidLauncherActivity.this).getWindowManager().getDefaultDisplay();
                    int orientation = display.getRotation();
                    if (orientation == Surface.ROTATION_0)
                    {
                        // EntryPoint.onDeviceMotionEvent(0.0f, acceleration_x, acceleration_y, acceleration_z, 0.0f, 0.0f, 0.0f);
                        // EntryPoint.onDeviceOrientationEvent(0.0f, 0.0f, 0.0f, 0.0f);
                        JNI.onAccelerationUpdate(acceleration_x, acceleration_y, acceleration_z);
                    }
                    else if (orientation == Surface.ROTATION_90)
                    {
                        // EntryPoint.onDeviceMotionEvent(0.0f, -acceleration_y, acceleration_x, acceleration_z, 0.0f, 0.0f, 0.0f);
                        // EntryPoint.onDeviceOrientationEvent(0.0f, 0.0f, 0.0f, 0.0f);
                        JNI.onAccelerationUpdate(-acceleration_y, acceleration_x, acceleration_z);
                    }
                    else if (orientation == Surface.ROTATION_180)
                    {
                        // EntryPoint.onDeviceMotionEvent(0.0f, -acceleration_x, -acceleration_y, acceleration_z, 0.0f, 0.0f, 0.0f);
                        // EntryPoint.onDeviceOrientationEvent(0.0f, 0.0f, 0.0f, 0.0f);
                        JNI.onAccelerationUpdate(-acceleration_x, -acceleration_y, acceleration_z);
                    }
                    else if (orientation == Surface.ROTATION_270)
                    {
                        // EntryPoint.onDeviceMotionEvent(0.0f, acceleration_y, -acceleration_x, acceleration_z, 0.0f, 0.0f, 0.0f);
                        // EntryPoint.onDeviceOrientationEvent(0.0f, 0.0f, 0.0f, 0.0f);
                        JNI.onAccelerationUpdate(acceleration_y, -acceleration_x, acceleration_z);
                    }
                }
            }
        };
    }

    private boolean copyFile(String dst, String src)
    {
        try
        {
            File outFile = new File(dst);
            outFile.delete();
            if(outFile.exists())
            {
                Log.d("copyFile: no need copy: ", dst + "<=" + src);
                return false;
            }

            Log.d("copyFile: copying", dst + "<=" + src);

            InputStream in = this.getAssets().open(src);
            OutputStream out = new FileOutputStream(outFile);
            byte[] buf = new byte[4096];
            int len;
            while ((len = in.read(buf)) > 0)
            {
                out.write(buf, 0, len);
            }

            in.close();
            out.close();
            return true;
        }
        catch (IOException e)
        {
            Log.d("copyFile: error", dst + "<=" + src);

            return false;
        }
    }

    private boolean copyAssetFiles(String dstRootPath, String assetPath)
    {
        String [] list;

        try
        {
            list = getAssets().list(assetPath);
            int length = list.length;
            if (list.length > 0)
            {
                for (String file : list)
                {
                    String newAssetPath = (assetPath=="" ? file : assetPath + "/" + file);
                    if (!copyAssetFiles(dstRootPath, newAssetPath))
                    {
                        return false;
                    }
                }
            }
            else
            {
                // File mWorkingPath = new File(dstRootPath);
                // if (!mWorkingPath.exists())
                // {
                //     mWorkingPath.mkdirs();
                //
                // copyFile(, path);
                // This is a file
                // TODO: add file name to an array list
                String dstPath = dstRootPath + assetPath;
                String dstDirectory = dstPath.substring(0, dstPath.lastIndexOf('/'));
                String filename = dstPath.substring(dstPath.lastIndexOf('/')+1);
                //Log.d("copyAssetFiles: ", dstRootPath + ", " + dstDirectory + ", "+ filename);

                File dstDirectoryFile = new File(dstDirectory);
                if (!dstDirectoryFile.exists()) {
                    dstDirectoryFile.mkdirs();
                }

                copyFile(dstPath, assetPath);
            }

            return true;
        }
        catch (IOException e)
        {
            return false;
        }
    }

    @Override protected void onCreate(Bundle icicle)
    {
        super.onCreate(icicle);
        mView = new JNIView(getApplication());
	    setContentView(mView);

        org.fmod.FMOD.init(this);
        // setStateCreate();

        ///////////////////////////
        sensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        initTouchSensor();
        initAccelerationSensor();

        //////////////////////////////////
        // prepare file
        String assetCopyDst = this.getFilesDir().getAbsolutePath() + "/";
        String assetRoot    = this.getFilesDir().getAbsolutePath() + "/device/application/bundle/";
        String documentRoot = this.getFilesDir().getAbsolutePath() + "/documents/";
        String externalRoot = this.getExternalFilesDir("").getAbsolutePath() + "/";

        //////////////////////////////////////////////////
        JNI.setPrintFunc();
        JNI.setGetCurrentTimeMSFunc();
        JNI.setRawAssetRootDirectory("");
        JNI.setAssetRootDirectory(assetRoot);
        JNI.setDocumentDirectory(documentRoot);
        JNI.setExternalDirectory(externalRoot);
        JNI.setInitialScene("PlayMode");

        copyAssetFiles(assetCopyDst, "");
    }

    @Override
    protected void onStart()
    {
        super.onStart();
        // setStateStart();
    }

    @Override protected void onPause()
    {
        super.onPause();

        mView.onPause();

        JNI.onPause();
    }

    @Override protected void onResume()
    {
        JNI.onResume();

        super.onResume();

        mView.onResume();
    }

    @Override
    protected void onStop()
    {
        // setStateStop();

        super.onStop();
    }

    @Override
    protected void onDestroy()
    {
        JNI.onTerminate();

        // setStateDestroy();

        org.fmod.FMOD.close();

        super.onDestroy();
    }
}
