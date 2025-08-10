import React from 'react'

const Header = () => {
  return (
    <div className='w-screen h-17 bg-black'>
      <button className='px-4 py-2 bg-green rounded-lg m-4'>
        Play Now
      </button>
      <button className='px-4 py-2 bg-green rounded-lg m-4'>
        Stop
      </button>
      <button className='px-4 py-2 bg-green rounded-lg m-4'>
        Animation Speed
      </button>
      <button className='px-4 py-2 bg-green rounded-lg m-4'>
        Generate New Array
      </button>
    </div>
  )
}

export default Header