export function VideoCard({
	thumbnail,
	channelImage,
	videoTitle,
	authorName,
	noOfViews,
	dateAdded,
}: any) {
	return (
		<div className="p-2 cursor-pointer">
			<img src={thumbnail} alt="first video card" className="rounded-xl" />
			<div className="grid grid-cols-12 pt-2">
				<div className="col-span-1">
					<img
						src={channelImage}
						alt="first video card"
						className={'rounded-full w-12 h-12 text-center '}
					/>
				</div>
				<div className="col-span-11 pl-5">
					<div>{videoTitle}</div>
					<div className="col-span-11 text-gray-500 text-base">
						{authorName}
					</div>
					<div className="col-span-11 text-gray-500 text-base">
						{noOfViews} | {dateAdded}
					</div>
				</div>
			</div>
		</div>
	);
}
