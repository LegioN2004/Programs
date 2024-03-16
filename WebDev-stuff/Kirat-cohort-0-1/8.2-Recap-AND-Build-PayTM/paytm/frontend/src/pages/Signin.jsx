import { BottomWarning } from '../components/BottomWarning';
import { Button } from '../components/Button';
import { Heading } from '../components/Heading';
import { InputBox } from '../components/InputBox';
import { SubHeading } from '../components/Subheading';
import { useNavigate } from 'react-router-dom';

export const Signin = () => {
	const navigate = useNavigate();
	return (
		<>
			<div className="h-screen bg-slate-400 flex justify-center">
				<div className="h-50">
					<div className="bg-white w-80 m-9 p-5 mx-auto rounded-lg">
						<div className="text-center">
							<Heading label={'Sign In'}></Heading>
							<SubHeading
								subheading={'Enter your credentials to access your account'}
							></SubHeading>
						</div>
						<div className="text-left">
							<InputBox
								label={'Email'}
								placeholder={'example johndoe@gmail.com'}
							></InputBox>
							<InputBox
								label={'Password'}
								placeholder={'Enter you password'}
							></InputBox>
						</div>
						<div className="text-left pt-3">
							<Button
								onClick={(e) => {
									navigate('/dashboard');
								}}
								label={'Sign In'}
							></Button>
						</div>
						<div className="text-left pt-3">
							<BottomWarning
								label={"Don't have an account yet,"}
								buttonText={'Sign up'}
								to={'/signup'}
							></BottomWarning>
						</div>
					</div>
				</div>
			</div>
		</>
	);
};
