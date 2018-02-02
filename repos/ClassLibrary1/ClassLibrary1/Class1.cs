using System;

namespace ClassLibrary1
{
    public class GasEngine : IEngine
    {
        private uint _curThrottle = 0;
        private uint _maxThrottle = 0;
        public GasEngine(uint maxThrottle)
        {
            _maxThrottle = maxThrottle;
        }
        public uint MaxThrottle
        {
            get { return _maxThrottle; }
        }
        public void SetThrottle(uint thr)
        {
            _curThrottle = thr;
            Console.WriteLine("Setting Throttle to {0}", thr);
        }
        public uint GetThrottle()
        {
            return _curThrottle;
        }
    }

    public class DieselEngine : IEngine
    {
        private uint _curThrottle = 0;
        private uint _maxThrottle = 0;
        public DieselEngine(uint maxThrottle)
        {
            _maxThrottle = maxThrottle;
        }
        public uint MaxThrottle
        {
            get { return _maxThrottle; }
        }
        public void SetThrottle(uint thr)
        {
            _curThrottle = thr;
            Console.WriteLine("Setting Throttle to {0}", thr);
        }
        public uint GetThrottle()
        {
            return _curThrottle;
        }
    }    public class MotorBike
    {
        private IEngine _engine = null;
        public MotorBike(IEngine engine)
        {
            _engine = engine;
        }
        public void RunAtHalfSpeed()
        {
            _engine.SetThrottle(_engine.MaxThrottle / 2);
        }
    }    public interface IEngine
    {
        void SetThrottle(uint thr);
        uint MaxThrottle { get; }
    }}
