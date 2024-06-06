#pragma once
#ifndef HAS_THREAD
#define HAS_THREAD 0
#endif

#include<atomic>
#include<chrono>
#include<functional>
#include<iostream>
#include<map>
#include<memory>
#include<stdexcept>

#if HAS_THREAD
#include<mutex>
#endif

namespace base
{
	class CancellationTokenSource;

	/// <summary>
	///		取消令牌
	/// </summary>
	class CancellationToken
	{
	private:
		friend class CancellationTokenSource;

		#if HAS_THREAD
		std::mutex _lock;
		#endif

		std::atomic_bool _is_cancellation_request = false;
		std::map<uint64_t, std::function<void(void)>> _delegates;

		void Cancel();

	public:
		/// <summary>
		///		是否需要取消
		/// </summary>
		/// <returns></returns>
		bool IsCancellationRequested() const;

		/// <summary>
		///		注册一个委托，当令牌取消时会被调用。可以多次调用注册多个委托。
		/// </summary>
		/// <param name="func"></param>
		/// <returns>返回一个 id，用来标识此次注册的委托。取消时可以用此 id 取消。</returns>
		uint64_t Register(std::function<void(void)> func);

		/// <summary>
		///		注销指定的取消时将被调用的委托。
		/// </summary>
		/// <param name="id">委托的 id</param>
		void Unregister(uint64_t id);
	};
}